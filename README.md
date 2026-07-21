# EasyX Project Collection

基于 **EasyX 图形库** 开发的一系列 C++ 项目集合，包含多个小游戏和实用工具。

## 技术栈

- **语言**: C++ (C++11/14)
- **图形库**: EasyX (2022版)
- **开发环境**: Visual Studio 2019/2022
- **平台**: Windows

## 项目结构

```
easyx-Project-C_CPP/
├── 2048/                    # 2048 游戏
├── gobang/                  # 五子棋游戏
├── mineSweeper/             # 扫雷游戏
├── pushBox/                 # 推箱子游戏
├── Easyx_Maye/              # 自定义UI库
├── StudentManagementSystem_CPP/  # 学生成绩管理系统
├── StudentManagementSystem_all/  # 学生管理系统完整版
├── EasyxProject.sln         # 解决方案文件
├── README.md                # 项目说明
└── CODE_ISSUES.md           # 代码问题报告
```

## 子项目介绍

### 1. 2048 游戏
- **路径**: [2048/](file:///C:/Users/Maye/Downloads/libSrc/easyx-Project-C_CPP/2048)
- **功能**: 经典2048数字合并游戏
- **操作方式**: 键盘方向键或 WASD 控制移动
- **特点**: 支持游戏胜利检测（达到2048）

### 2. 五子棋游戏
- **路径**: [gobang/](file:///C:/Users/Maye/Downloads/libSrc/easyx-Project-C_CPP/gobang)
- **功能**: 双人对战五子棋
- **操作方式**: 鼠标点击棋盘落子
- **特点**: 支持胜负判定、背景音乐

### 3. 扫雷游戏
- **路径**: [mineSweeper/](file:///C:/Users/Maye/Downloads/libSrc/easyx-Project-C_CPP/mineSweeper)
- **功能**: 经典扫雷游戏
- **操作方式**: 左键打开格子，右键标记地雷
- **特点**: 支持自动展开空白区域、游戏重新开始

### 4. 推箱子游戏
- **路径**: [pushBox/](file:///C:/Users/Maye/Downloads/libSrc/easyx-Project-C_CPP/pushBox)
- **功能**: 经典推箱子益智游戏
- **操作方式**: 键盘方向键控制移动，空格键回退
- **特点**: 多关卡支持、状态回退功能

### 5. Easyx_Maye 库
- **路径**: [Easyx_Maye/](file:///C:/Users/Maye/Downloads/libSrc/easyx-Project-C_CPP/Easyx_Maye)
- **功能**: 基于 EasyX 的自定义UI框架
- **组件**:
  - Window (窗口管理)
  - BasicWidget (基础控件)
  - PushButton (按钮)
  - LineEdit (输入框)
  - Table (表格)
  - Image (图片处理)
  - Timer (定时器)

### 6. 学生成绩管理系统
- **路径**: [StudentManagementSystem_CPP/](file:///C:/Users/Maye/Downloads/libSrc/easyx-Project-C_CPP/StudentManagementSystem_CPP)
- **功能**: 学生信息管理系统（GUI版）
- **功能模块**:
  - 查看学生列表
  - 添加学生
  - 删除学生
  - 修改学生（待实现）
  - 查找学生
  - 数据持久化（文件存储）

## 编译运行

### 环境要求

1. 安装 **Visual Studio 2019** 或更高版本
2. 安装 **EasyX 图形库**（[官网下载](https://easyx.cn/)）

### 编译步骤

1. 使用 Visual Studio 打开 `EasyxProject.sln`
2. 在解决方案资源管理器中选择目标项目
3. 右键点击项目 -> "生成" 或按 `Ctrl+Shift+B`
4. 生成成功后，点击 "开始执行" 或按 `F5`

### 注意事项

- 所有项目均需链接 `Easyx_Maye.lib` 库
- 确保资源文件路径正确（图片、音乐等）
- 建议使用 **x86** 平台编译

## 代码问题报告

本项目存在一些代码问题，已整理至 [CODE_ISSUES.md](file:///C:/Users/Maye/Downloads/libSrc/easyx-Project-C_CPP/CODE_ISSUES.md)，包括：

- 内存泄漏问题
- 数组越界风险
- 逻辑错误
- 代码重复
- 命名规范问题

建议在开发和维护时参考该报告进行修复。

## 项目说明

本项目是基于 EasyX 图形库的学习和实践项目，包含多个经典小游戏和实用工具的实现。代码结构清晰，适合作为 C++ 图形编程的学习参考。

## License

本项目仅供学习和参考使用。