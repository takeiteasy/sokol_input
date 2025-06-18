import os
from enum import Enum

with open("src/sokol_input.h", "r") as fh:
    lines = [line.rstrip() for line in fh.readlines()]

first_half = []
middle_bits = []
second_half = []

class ReadState(Enum):
    FIRST_HALF = 0,
    MIDDLE = 1,
    SECOND_HALF = 2

state = ReadState.FIRST_HALF
for line in lines:
    match state:
        case ReadState.FIRST_HALF:
            if line == "// INCLUDES":
                state = ReadState.MIDDLE
            else:
                first_half.append(line)
        case ReadState.MIDDLE:
            if not line or line.isspace():
                state = ReadState.SECOND_HALF
            else:
                middle_bits.append(line)
        case ReadState.SECOND_HALF:
            second_half.append(line)

raw_includes = ["Gamepad.h", "Gamepad_private.h", "Gamepad_private.c"]

with open("sokol_input.h", "w+") as fh:
    fh.write("\n".join(first_half) + "\n")
    for line in middle_bits:
        if line.startswith("#include"):
            path = line.split(" ")[-1][1:-1]
            if path.split("/")[-1] in raw_includes:
                with open("src/" + path, "r") as _fh:
                    for _line in _fh.readlines():
                        if not _line.startswith("#include \"gamepad"):
                            fh.write(_line)
            start_writing = False
            with open("src/" + path, "r") as _fh:
                for _line in _fh.readlines():
                    if not start_writing:
                        if _line.rstrip() == "#include \"gamepad/Gamepad_private.h\"":
                            start_writing = True
                    else:
                        fh.write(_line)
        else:
            fh.write(line + "\n")
    fh.write("\n" + "\n".join(second_half))
