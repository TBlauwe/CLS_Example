# CLS_Example

<div align="center">

[![Windows [Clang-cl & MSVC]](https://github.com/TBlauwe/CLS_Example/actions/workflows/windows.yaml/badge.svg)](https://github.com/TBlauwe/CLS_Example/actions/workflows/windows.yaml)
[![Ubuntu & MacOS [Clang & GCC]](https://github.com/TBlauwe/CLS_Example/actions/workflows/ubuntu.yaml/badge.svg)](https://github.com/TBlauwe/CLS_Example/actions/workflows/ubuntu.yaml)
[![Documentation build & deploy](https://github.com/TBlauwe/CLS_Example/actions/workflows/documentation.yaml/badge.svg)](https://github.com/TBlauwe/CLS_Example/actions/workflows/documentation.yaml)
[![Static Badge](https://img.shields.io/badge/Documentation-blue?logo=readthedocs&logoColor=white&style=for-the-badge)](https://TBlauwe.github.io/CLS_Example/)

Here is an example of a generated project from the template.

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

