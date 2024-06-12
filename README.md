English is not my native language; please excuse typing errors.
- update 2024.6.12：修复了一堆 bug，现在使用 FFT 不会警告了。
- update 2024.5.30：特化了 $4$ 点 FFT，略微提升效率。
- update 2024.5.27：现支持使用 `cstdio` 进行 IO 了，制作了两个函数 `input(ulllint& x)` 和 `output(ulllint& x)` 进行基于 `scanf` 和 `printf` 的 IO。
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

乘法使用 FFT 实现。

All of the following sentences are from a website named [DeepL](https://www.deepl.com/en/translator).

- update 2024.5.22: Fixed a bunch of bugs, added comparing sizes (**C++ 20** compiled above is implemented slightly differently than C++ 20 below), and started writing division.

Handwritten big **integer** number library, average efficiency, requires C++ 11+ compilation, make sure `BigInt.h`, `Types.h`, `FastFTransForm.h`, `Constant.h` are in the same folder when using it.

- `BigInt.h` contains the large integer library
- `Types.h` contains type aliases and complex numbers class.
- `FastFTransForm.h` contains the FFT (Fast Fourier Transform).
- `Constant.h` for constants, and some common functions (currently only $\pi$ and its $2,6$ multiples, `max`, `min`.)
- If IO is needed, include `iostream` and `iomanip` and **precede `BigInt.h`**.

The big integer class is called `ulllint`, meaning `unsigned long long long int`.

`__BigFloat` is written for division, so there is no division or IO, and **no guarantee of correctness or stability when used in other contexts**. 

It is not intended to support bit shifting operations, if it did, a left shift of one bit would be a multiplication by $10^4$, a right shift would be the same.

Suppressing $4$ bits will store up to $10^6$ bits (before suppression).

Multiplication is implemented using FFT.
