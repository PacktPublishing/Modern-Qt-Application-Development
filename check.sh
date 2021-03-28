#!/bin/bash

cd $1

echo "================"
echo "Running cppcheck"
echo "================"
cppcheck --language=c++ --std=c++17 --inline-suppr --suppressions-list=/app/.cppcheck-suppressions --enable=all --template='{file}:{line}:{severity}:{id}:{message}' -q ./

echo "==============="
echo "Running cpplint"
echo "==============="
find ./ -name "*.h" -o -name "*.cpp" | grep -v build | xargs cpplint --quiet

echo "============="
echo "Running clazy"
echo "============="
mkdir build-clazy && cd build-clazy
export CLAZY_CHECKS="level0,level1,level2,`pacman -Ql clazy | grep manuallevel | grep README | grep -v jni | sed -n 's/.*README\-\(.*\)\.md.*/\1/p' | paste -sd ","`,no-ifndef-define-typo,no-qt6-qlatin1stringchar-to-u"
echo "Clazy checks: $CLAZY_CHECKS"
cmake -GNinja -DCMAKE_CXX_COMPILER=clazy -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
cmake --build .
cd ..

echo "=================="
echo "Running clang-tidy"
echo "=================="
find ./ -name "*.h" -o -name "*.cpp" | grep -v build | xargs clang-tidy --quiet -p build-clazy/compile_commands.json
rm -rf build-clazy

echo "===================="
echo "Running clang-format"
echo "===================="
find ./ -name "*.h" -o -name "*.cpp" | grep -v build | xargs clang-format --dry-run --Werror
