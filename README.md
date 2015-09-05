# 简介

- 该模块主要对node进行c/c++扩展,来完成node的(&,|,^,~,<<,>>)运算

# 编译说明

- 编译命令:node-gyp configure build
- 接下来会产生build文件夹,在build/Release/bit.node文件

# 使用说明

```
var bit = require('bit.node');

console.log(bit.and(10,3));
console.log(bit.and(10,3));
console.log(bit.and(10,3));


```
