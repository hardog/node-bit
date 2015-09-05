# 简介

- 该模块主要对node进行c/c++扩展,来完成node的(&,|,^,~,<<,>>)运算

# 编译说明

- 编译命令:node-gyp configure build
- 接下来会产生build文件夹,会产生build/Release/bit.node文件

# 使用说明

```
var bit = require('bit.node');

console.log(bit.and(10,3));       //与
console.log(bit.or(10,3));        //或
console.log(bit.not(10,3));       //非
console.log(bit.xor(10,3));       //异或
console.log(bit.rightmove(10,3)); //右移
console.log(bit.leftmove(10,3));  //左移

```
