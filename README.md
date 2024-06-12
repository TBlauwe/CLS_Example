![C++](https://img.shields.io/badge/c++%2020%20Library-%2300599C.svg?style=for-the-badge&logo=cplusplus&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%232B2F33.svg?style=for-the-badge&logo=cmake)
[![Version](https://img.shields.io/github/v/release/TBlauwe/CLS_Example?include_prereleases&style=for-the-badge)](https://github.com/TBlauwe/CLS_Example/releases)
[![MIT](https://img.shields.io/badge/license-TBD-blue.svg?style=for-the-badge)](https://github.com/TBlauwe/CLS_Example/blob/master/LICENSE)
[![Documentation link](https://img.shields.io/badge/Docs-blue?logo=readthedocs&logoColor=white&style=for-the-badge)](https://TBlauwe.github.io/CLS_Example/)
[![Examples](https://img.shields.io/badge/Examples-darkviolet?&style=for-the-badge)](https://TBlauwe.github.io/CLS_Example/examples.html)

![Windows GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/TBlauwe/CLS_Example/windows.yaml?style=flat-square&logo=windows10&label=Windows%20(Clang-cl%2C%20MSVC))
![Ubuntu GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/TBlauwe/CLS_Example/ubuntu.yaml?style=flat-square&logo=ubuntu&logoColor=white&label=Ubuntu%20(Clang%2C%20GCC))
![MacOS GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/TBlauwe/CLS_Example/ubuntu.yaml?style=flat-square&logo=apple&logoColor=white&label=MacOS%20(Clang%2C%20GCC))
![Documentation GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/TBlauwe/CLS_Example/documentation.yaml?style=flat-square&logo=github&logoColor=white&label=Documentation)

</br>

<div align="center">

Repository generated from cpp_lib_starter template repository

</div>


## Features

* 

## Getting started

### Installation

Using **[CPM](https://github.com/cpm-cmake/)**, add the following lines to your cmake file:

```cmake
CPMAddPackage(
  NAME CLS_Example
  GITHUB_REPOSITORY TBlauwe/CLS_Example
)

target_link_libraries(your_target PUBLIC CLS_Example)
```

<details>
<summary> CMake options </summary>

| Options | Default | Description |
| ---: | :---: | :--- |
| `CLS_EXAMPLE_SKIP_DEPENDENCIES` | `true` in consumer mode, `false` otherwise | Disable automatic dependencies downloading with **[CPM](https://github.com/cpm-cmake/)** |
| `CPM_MY_DEPENDENCY_VERSION` | `true` in consumer mode, `false` otherwise | Override a dependency's version. Value must be a git tag, e.g `master`, `v3.12`, `1.0` |

</details>

### Minimal example

<!--BEGIN_INCLUDE="examples/getting_started.cpp"-->
```cpp
#include <CLS_Example/core.h>
```
<!--END_INCLUDE-->

