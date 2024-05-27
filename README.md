- update 2024.5.22：修复了一堆 bug，增加了比较大小（**C++ 20** 以上编译的实现方式和 C++ 20 以下略有不同），开始了除法的编写。

手写的大**整**数库，效率一般，需要 C++ 11 以上编译，使用时请确保 `BigInt.h`，`Types.h`，`FastFTransForm.h`，`Constant.h` 在同一文件夹。

- `BigInt.h` 内即为大整数库
- `Types.h` 内为类型别名和复数类。
- `FastFTransForm.h` 内为 FFT（快速傅里叶变换）。
- `Constant.h` 为常量，和一些常用函数（目前只有 $\pi$ 和它的 $2,6$ 倍，`max`，`min`。）
- 如果需要 IO 请引入 `iostream` 和 `iomanip` 并**置于 `BigInt.h` 之前**。

大整数类名为 `ulllint`，意即 `unsigned long long long int`。

`__BigFloat` 是为了除法而编写的，因此没有除法和 IO，也**不能保证用在其它场合时的正确性和稳定性**。 

不打算支持位移运算，如果支持了，左移一位是乘以 $10^4$，右移同理。

压 $4$ 位，最多（压前）存 $10^6$ 位数。

乘法效率使用 FFT 实现。
