# Sample-CPP-Project

## vcpkg 结合 cmake

1. 将 vcpkg 作为 Git 子模块添加
    ```sh
    git submodule add https://github.com/microsoft/vcpkg.git
    ```
2. 初始化更新子模块
    ```sh
    git submodule add https://github.com/microsoft/vcpkg.git
    ```
3. 安装依赖，以 Google Test 为例
    ```sh
    ./vcpkg/vcpkg install gtest
    ```
4. 配置 `CMakeLists.txt`：在你的 `CMakeLists.txt` 文件中，设置 `CMAKE_TOOLCHAIN_FILE` 变量以指向 vcpkg 的工具链文件。这可以在项目的第一个 `project()` 调用之前完成：
    ```cmake
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")
    ```

## 配置 `clang-format`

`clangd` 集成了 `clang-format`，配置参考[网站](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)。

1. 导出预设配置
    ```sh
    clang-format -style=llvm -dump-config > .clang-format
    ```
    可以使用的预设包括：LLVM、Google、Chromium、Mozilla、WebKit、Microsoft、GNU。
2. 修改导出的配置，比如将 缩进 调整为4个空格：
    ```
    IndentWidth: 4
    ```
