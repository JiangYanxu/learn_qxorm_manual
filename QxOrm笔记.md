# 笔记
## 学到了什么？
### 宏
```cpp
// exprot.hpp
#ifndef EXPORT_HPP
#define EXPORT_HPP

#include <QxOrm.h>
#ifdef BUILD_MY_DEMO
#define QX_MY_DEMO_EXPORT QX_DLL_EXPORT_HELPER
#define QX_REGISTER_HPP_MY_DEMO  QX_REGISTER_HPP_EXPORT_DLL
#define QX_REGISTER_CPP_MY_DEMO  QX_REGISTER_CPP_EXPORT_DLL
#else
#define QX_MY_DEMO_EXPORT QX_DLL_IMPORT_HELPER
#define QX_REGISTER_HPP_MY_DEMO  QX_REGISTER_HPP_IMPORT_DLL
#define QX_REGISTER_CPP_MY_DEMO  QX_REGISTER_CPP_IMPORT_DLL
#endif

#endif // EXPORT_HPP
```
#### 说明
* 文档说要通过`QX_REGISTER_HPP`与`QX_REGISTER_CPP`宏来注册, 也好用.
  上面`export.hpp`内容是参考官方例子写出来的, 贴在这里目的是做个记录.
