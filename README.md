![C++](https://img.shields.io/badge/c++%20Library-%2300599C.svg?style=for-the-badge&logo=cplusplus&logoColor=white)
# CLS_Example
![Windows GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/TBlauwe/CLS_Example/windows.yaml?style=flat-square&logo=windows10&label=Windows%20(Clang-cl%2C%20MSVC))
![Ubuntu GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/TBlauwe/CLS_Example/ubuntu.yaml?style=flat-square&logo=ubuntu&logoColor=white&label=Ubuntu%20(Clang%2C%20GCC))
![MacOS GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/TBlauwe/CLS_Example/ubuntu.yaml?style=flat-square&logo=apple&logoColor=white&label=MacOS%20(Clang%2C%20GCC))
![Documentation GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/TBlauwe/CLS_Example/documentation.yaml?style=flat-square&logo=github&logoColor=white&label=Documentation)

<div align="center">

Here is an example of a generated project from the template.


[![Static Badge](https://img.shields.io/badge/Documentation-blue?logo=readthedocs&logoColor=white&style=for-the-badge)](https://TBlauwe.github.io/CLS_Example/)

</div>


## Features


## Getting started

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

In your code : 

```cpp
#include <CLS_Example/CLS_Example.h>
```

