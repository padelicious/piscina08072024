#!/bin/bash

# Obtém os IDs dos 5 últimos commits
last_commits=$(git log --pretty=format:"%H" -n 5)

echo "Os IDs dos 5 últimos commits são:"
echo "$last_commits"
