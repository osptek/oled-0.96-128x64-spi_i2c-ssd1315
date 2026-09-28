<p align="left"><img alt="OSPTEK" src="./images/logo.png" width="200" /></p>

<h1 align="center">OSPTEK 0.96″ OLED 128×64（SSD1315 · SPI / I2C）</h1>

<p align="center"><b>单色 OLED · SPI / I2C · SSD1315</b></p>

<p align="center"><a href="./README_EN.md">English</a> | 简体中文 · <a href="../../README.md">规格族索引</a></p>

<p align="center">
  <img alt="Size: 0.96 inch" src="https://img.shields.io/badge/Size-0.96%22-3498DB?style=flat-square" />
  <img alt="Resolution: 128x64" src="https://img.shields.io/badge/Resolution-128%C3%9764-8E44AD?style=flat-square" />
  <img alt="Interface: SPI / I2C" src="https://img.shields.io/badge/Interface-SPI%20%2F%20I2C-27AE60?style=flat-square" />
  <img alt="Driver: SSD1315" src="https://img.shields.io/badge/Driver-SSD1315-E7352C?style=flat-square" />
</p>

<p align="center"><img alt="OSPTEK 0.96 寸 128×64 OLED SPI / I2C 模组（SSD1315）宣传图" src="./images/product.png" width="640" /></p>

## 目录

- [产品简介](#产品简介)
- [规格参数](#规格参数)
- [示例工程](#示例工程)
- [仓库结构](#仓库结构)
- [相关资料](#相关资料)
- [购买链接](#购买链接)
- [技术支持](#技术支持)

---

## 产品简介

OSPTEK **0.96 寸 128×64 OLED** 是一款 **SPI / I2C** 白色单色显示模组，驱动为 **SSD1315**。适合状态栏、菜单提示与小型调试显示。

规格标识（仓库名）：`oled-0.96-128x64-spi_i2c-ssd1315`

当前模组版本：**OED096-12864W009-C30**。电气与外形细节以 [`docs/OED096-12864W009-C30.pdf`](./docs/OED096-12864W009-C30.pdf) 为准。

## 规格参数

| 项目 | 规格 |
| ---- | ---- |
| 尺寸 | 0.96 英寸 |
| 类型 | OLED（单色，白色） |
| 分辨率 | 128×64 |
| 接口 | SPI / I2C |
| 驱动 IC | SSD1315 |

> 完整外形尺寸、FPC 定义、供电与时序以产品规格书 / 驱动手册为准。

## 示例工程

| 说明 | 路径 |
| ---- | ---- |
| ESP32-S3 · S3 DEMO 底板 · SSD1315 I2C 表情动画 | [`examples/s3-demo-board/`](./examples/s3-demo-board/) |

## 仓库结构

```text
oled-0.96-128x64-spi_i2c-ssd1315/         # 仓库根（导航见 ../../README.md）
└── versions/
    └── OED096-12864W009-C30/             # 本料号完整资料
        ├── README.md
        ├── README_EN.md
        ├── images/
        ├── docs/
        └── examples/
```

## 相关资料

### 本产品资料

| 资料 | 链接 |
| ---- | ---- |
| 产品规格书（OED096-12864W009-C30） | [`docs/OED096-12864W009-C30.pdf`](./docs/OED096-12864W009-C30.pdf) |
| 驱动 IC 数据手册（SSD1315） | [`docs/SSD1315.pdf`](./docs/SSD1315.pdf) |
| SSD1315 SPI 初始化代码 | [`docs/ssd1315-spi-init.c`](./docs/ssd1315-spi-init.c) |

### 示例工程

- [ESP32-S3 · S3 DEMO 底板 · SSD1315 I2C](./examples/s3-demo-board/)

## 购买链接

<p align="center">
  <a href="https://shop110742373.taobao.com/"><img alt="淘宝官方店铺" src="https://img.shields.io/badge/淘宝-官方店铺-FF6A00?style=for-the-badge" /></a>
  &nbsp;&nbsp;
  <a href="https://www.aliexpress.com/store/1105701619"><img alt="速卖通官方店铺" src="https://img.shields.io/badge/速卖通-官方店铺-E62E04?style=for-the-badge&logo=aliexpress&logoColor=white" /></a>
</p>

**国内（淘宝）**

- 店铺：[鱼鹰光电工厂店](https://shop110742373.taobao.com/)

**海外（AliExpress）**

- 店铺：[OSPTEK Official Store](https://www.aliexpress.com/store/1105701619)

## 技术支持

- 技术支持 / 产品咨询：<luyu@osptek.com>
- QQ 技术交流群：**985881096**
- 公司官网：<https://osptek.com/>
- 有任何问题，都可以在本仓库 Issues 中提问

---

<p align="center"><sub>© 2026 OSPTEK 鱼鹰光电 · 本仓库资料采用 CC BY 4.0 许可</sub></p>
