#!/usr/bin/env sh

python generate.py
headerdoc2html -p -o docs sokol_input.h
mv docs/sokol_input_h/*.html docs
rm -rf docs/sokol_input_h