#!/bin/sh
echo "Running pre-commit resource sync..."
bash build.sh -rsf
echo "Resource sync complete — continuing commit."
git add .
git commit -m "$1"