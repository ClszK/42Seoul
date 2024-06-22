#!/bin/bash

# 현재 디렉토리부터 하위 디렉토리까지 모든 makefile을 찾음
find . -type f -name 'makefile' -o -name 'Makefile' | while read makefile
do
    # makefile이 있는 디렉토리로 이동
    dir=$(dirname "$makefile")
    echo "Running make fclean in $dir"
    (cd "$dir" && make fclean) || echo "make fclean failed in $dir, continuing..."
done

