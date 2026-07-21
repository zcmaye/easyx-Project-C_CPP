# 代码问题报告

## 一、内存泄漏问题

### 1.1 mineSweeper/map.cpp
**问题位置**: 第71行
```cpp
m_imgs.push_back(new Image(imgPath,40,40));
```
**问题描述**: 动态分配的Image对象存储在vector中，但从未释放，导致内存泄漏。

**修复建议**:
```cpp
// 在析构函数中释放内存
~Map() {
    for (auto img : m_imgs) {
        delete img;
    }
}
```

---

### 1.2 pushBox/controller.cpp
**问题位置**: 第49行
```cpp
m_imgs.push_back(new Image(path));
```
**问题描述**: 同上，动态分配的Image对象没有释放。

**修复建议**: 在Controller类中添加析构函数释放资源。

---

### 1.3 pushBox/map.h
**问题位置**: 第134行
```cpp
Pointer tmap = new MapArr{ 0 };
```
**问题描述**: 动态分配的二维数组存储在vector中，但从未释放。

**修复建议**: 在Map类中添加析构函数释放所有地图数据。

---

## 二、使用exit()函数不当

### 2.1 2048/controller.cpp
**问题位置**: 第213行
```cpp
exit(666);
```
**问题描述**: 使用魔法数字退出程序，不符合良好的编程习惯。

---

### 2.2 gobang/controller.cpp
**问题位置**: 第28行
```cpp
exit(66);
```
**问题描述**: 同上，使用魔法数字退出。

---

### 2.3 mineSweeper/controller.cpp
**问题位置**: 第37行
```cpp
exit(0);
```
**问题描述**: 使用exit()退出主循环，应该通过正常流程退出。

**修复建议**: 使用标志位控制主循环退出，而不是直接调用exit()。

---

## 三、数组越界风险

### 3.1 2048/map.h
**问题位置**: 第35-36行
```cpp
int index = (int)log2(m_map[i][k]);
DWORD tempcolor = colors[index];
```
**问题描述**: 当数值超过2048时（如4096、8192等），index会超过colors数组的边界（最大为11），导致未定义行为。

**修复建议**: 添加边界检查，超过最大索引时使用默认颜色。

---

### 3.2 pushBox/gamer.cpp
**问题位置**: 第28行
```cpp
int (*map)[10] = m_map->getCurMap();
```
**问题描述**: 硬编码数组大小为10，与模板参数不一致时会导致问题。

**修复建议**: 使用模板参数COL替代硬编码的10。

---

## 四、逻辑错误

### 4.1 gobang/chessPieces.cpp
**问题位置**: 第32-35行
```cpp
bool ChessPieces::operator==(const ChessPieces& right)const
{
    return (m_x == right.m_x && m_y == right.m_y && m_colorPiece != ChessPieces::None);
}
```
**问题描述**: operator==的实现不正确，它比较的是坐标而不是棋子颜色，导致judge函数无法正确判断胜负。

**修复建议**:
```cpp
bool ChessPieces::operator==(const ChessPieces& right)const
{
    return m_colorPiece == right.m_colorPiece;
}
```

---

### 4.2 2048/controller.cpp
**问题位置**: 第197-218行
```cpp
void Controller::GameWin()
{
    for (int i = 0; i < map.rows(); i++)
    {
        for (int k = 0; k < map.cols(); k++)
        {
            if (map[i][k] == 2048)
            {
                // 弹出对话框
            }
        }
    }
}
```
**问题描述**: 每次循环都会检查是否赢了，如果已经赢了会重复弹出对话框。

**修复建议**: 添加一个标志位，只在第一次达到2048时弹出对话框。

---

### 4.3 mineSweeper/controller.cpp
**问题位置**: 第122-138行
```cpp
static int cnt = 0;
for (int i = 0; i < m_map.rows(); i++)
{
    for (int k = 0; k < m_map.cols(); k++)
    {
        if (m_map[i][k] >= 0 && m_map[i][k] <= 8)
        {
            cnt++;
        }
    }
}
if (cnt == m_map.rows() * m_map.cols() - 10)
{
    isWin = true;
}
cnt = 0;
```
**问题描述**: 使用静态变量cnt计数，但每次循环后重置为0，逻辑混乱。更严重的是，cnt在每次judge调用时都会累加，而不是统计当前打开的格子数。

**修复建议**: 将cnt改为局部变量，或者使用更好的方式统计已打开的格子。

---

## 五、代码重复

### 5.1 2048/controller.cpp
**问题描述**: moveup, movedown, moveleft, moveright 四个函数逻辑几乎相同，只是方向不同，存在大量重复代码。

**修复建议**: 提取公共逻辑，使用方向参数统一处理。

---

## 六、命名问题

### 6.1 gobang/checkerBoard.cpp
**问题描述**: 变量名如 `opx`, `opy`, `opr`, `opc` 不够清晰，难以理解其含义。

**修复建议**: 改为更有意义的名称，如 `mouseX`, `mouseY`, `mouseRow`, `mouseCol`。

---

### 6.2 pushBox/gamer.cpp
**问题位置**: 第19行
```cpp
char m_dir;  //保存刚才移动的方向
```
**问题描述**: 变量名m_dir类型为char，但存储的是键盘码（如72、80等），容易引起混淆。

**修复建议**: 改为int类型或使用枚举。

---

## 七、头文件重复包含

### 7.1 StudentManagementSystem_CPP/ManageMent_gui.cpp
**问题位置**: 第2行和第10行
```cpp
#include<sstream>
// ...
#include<sstream>
```
**问题描述**: 重复包含相同的头文件。

**修复建议**: 删除重复的#include。

---

## 八、const使用不规范

### 8.1 2048/map.cpp
**问题位置**: 第57-65行
```cpp
int Map::rows()
{
    return m_rows;
}

int Map::cols()
{
    return m_cols;
}
```
**问题描述**: 这些函数不修改成员变量，应该声明为const成员函数。

**修复建议**:
```cpp
int Map::rows() const
{
    return m_rows;
}

int Map::cols() const
{
    return m_cols;
}
```

---

## 九、未实现的功能

### 9.1 StudentManagementSystem_CPP/ManageMent_gui.cpp
**问题位置**: 第299-305行
```cpp
void ManageMent::modify()
{
    settextstyle(50, 0, "黑体");
    char title[50] = "修改学生";
    outtextxy((Window::width() - textwidth(title)) / 2, 50, title);
    //略
}
```
**问题描述**: 修改学生功能未实现，只有标题显示。

---

## 十、代码风格不一致

### 10.1 使用namespace std
**问题描述**: 部分文件使用了 `using namespace std;`（如Student.cpp），而其他文件没有（如map.cpp），导致代码风格不一致。

**修复建议**: 统一代码风格，建议不使用using namespace std。

---

## 十一、缺少错误处理

### 11.1 gobang/controller.cpp
**问题位置**: 第7行
```cpp
m_bk = Image("./resource/images/bk.jpg");
```
**问题描述**: 图片加载失败时没有错误检查。

**修复建议**: 添加资源加载失败的处理逻辑。

---

## 十二、Easyx_Maye库问题

### 12.1 Window.h
**问题位置**: 第29行
```cpp
inline int exec() { system("pause"); return 0; };
```
**问题描述**: 使用system("pause")作为exec()的实现，这不是一个好的设计。

**修复建议**: 使用消息循环替代。

---

## 十三、Color枚举值错误

### 13.1 Easyx_Maye/include/commonutils/Color.h
**问题描述**: Color枚举中的颜色值使用的是BGR顺序（EasyX使用BGR），但注释中没有说明，容易引起混淆。

例如:
```cpp
Blue = 0xAA0000,  // 实际显示为红色（BGR）
Red = 0x0000AA,   // 实际显示为蓝色（BGR）
```

**修复建议**: 在注释中明确说明使用的是BGR颜色顺序。

---

## 问题统计

| 类别 | 数量 | 严重程度 |
|------|------|----------|
| 内存泄漏 | 3 | 高 |
| 数组越界 | 2 | 高 |
| 逻辑错误 | 3 | 高 |
| 代码重复 | 1 | 中 |
| 命名问题 | 2 | 低 |
| const使用 | 1 | 低 |
| 头文件重复 | 1 | 低 |
| 未实现功能 | 1 | 中 |
| exit()使用 | 3 | 中 |
| 缺少错误处理 | 1 | 中 |

---

## 优先级建议

1. **高优先级**：修复内存泄漏、数组越界和逻辑错误
2. **中优先级**：提取重复代码、添加错误处理、修复exit()使用
3. **低优先级**：规范命名、const使用、统一代码风格