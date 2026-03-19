#!/bin/bash

# This script generates a markdown file for a given LeetCode problem slug using the leet_code_md_gen.py script.
# Usage: ./run_leetcode.sh <problem-slug>
# But first, make it executable: chmod +x ./scripts/leet_code_md_gen/script.sh

# e.g.:
# ./scripts/leet_code_md_gen/script.sh linked-list-cycle

set -e

# ---- RESOLVE SCRIPT DIRECTORY (works even if called from elsewhere) ----
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

VENV_DIR="$SCRIPT_DIR/venv"
PYTHON_SCRIPT="$SCRIPT_DIR/leet_code_md_gen.py"

# ---- CHECK ARG ----
if [ -z "$1" ]; then
  echo "Usage: ./run_leetcode.sh <problem-slug>"
  exit 1
fi

SLUG=$1

# ---- VENV ----
if [ ! -d "$VENV_DIR" ]; then
  # ---- VENV DOES NOT EXIST ----
  echo "Virtual environment not found at $VENV_DIR"
  echo "Creating virtual environment and installing dependencies..."
  python3 -m venv "$VENV_DIR"
  source "$VENV_DIR/bin/activate"
  pip install --upgrade pip
  pip install -r "$SCRIPT_DIR/requirements.txt"
else
  # ---- ACTIVATE VENV ----
  echo "Virtual environment found at $VENV_DIR"
  echo "Activating virtual environment at $VENV_DIR"
  source "$VENV_DIR/bin/activate"
fi

# Ensure deactivation even if script fails
trap "deactivate" EXIT

# ---- RUN SCRIPT ----
echo "Running script for slug: $SLUG"
python "$PYTHON_SCRIPT" "$SLUG"

echo "Done."