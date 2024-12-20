C++ Standard Template Library (STL) 提供了一些常用的数据结构和算法，下面是一些常见的 STL 容器与其对应的数据结构：

### 1. **Vector (`std::vector`)**
   - **底层数据结构**：动态数组
   - **特点**：支持随机访问、动态扩展、按需增长的数组，具有较高的插入和删除性能（如果是在末尾插入/删除时）。
   
### 2. **List (`std::list`)**
   - **底层数据结构**：双向链表
   - **特点**：支持高效的插入和删除操作，但不支持随机访问。适用于需要频繁在容器中间插入/删除元素的场景。

### 3. **Deque (`std::deque`)**
   - **底层数据结构**：双端队列
   - **特点**：提供对两端的高效插入和删除，支持随机访问。适合在两端进行操作的场景。

### 4. **Queue (`std::queue`)**
   - **底层数据结构**：通常基于 `std::deque` 或 `std::list`
   - **特点**：遵循先进先出 (FIFO) 队列规则，支持高效的插入和删除操作，只能从队头进行访问。

### 5. **Stack (`std::stack`)**
   - **底层数据结构**：通常基于 `std::deque` 或 `std::vector`
   - **特点**：遵循后进先出 (LIFO) 栈规则，只能在栈顶进行插入和删除操作。

### 6. **Set (`std::set`)**
   - **底层数据结构**：红黑树（平衡二叉搜索树）
   - **特点**：不允许重复元素，自动排序，支持高效的查找、插入和删除操作（O(log n)）。

### 7. **Multiset (`std::multiset`)**
   - **底层数据结构**：红黑树（平衡二叉搜索树）
   - **特点**：允许重复元素，自动排序，支持高效的查找、插入和删除操作。

### 8. **Map (`std::map`)**
   - **底层数据结构**：红黑树（平衡二叉搜索树）
   - **特点**：键值对（key-value）映射，键唯一并自动排序，支持高效的查找、插入和删除操作。

### 9. **Multimap (`std::multimap`)**
   - **底层数据结构**：红黑树（平衡二叉搜索树）
   - **特点**：键值对（key-value）映射，允许键重复，自动排序。

### 10. **Unordered Set (`std::unordered_set`)**
   - **底层数据结构**：哈希表
   - **特点**：元素无序，提供常数时间复杂度的查找、插入和删除操作（O(1)，最坏情况下 O(n)）。

### 11. **Unordered Map (`std::unordered_map`)**
   - **底层数据结构**：哈希表
   - **特点**：键值对（key-value）映射，键无序，提供常数时间复杂度的查找、插入和删除操作。

### 12. **Priority Queue (`std::priority_queue`)**
   - **底层数据结构**：堆（通常是最大堆）
   - **特点**：支持按照优先级顺序访问元素，最小/最大元素优先。适用于需要按照优先级处理元素的场景。

### 13. **Array (`std::array`)**
   - **底层数据结构**：静态数组
   - **特点**：在编译时固定大小的数组，提供与 C 风格数组类似的功能，支持更安全和方便的操作。

### 14. **Forward List (`std::forward_list`)**
   - **底层数据结构**：单向链表
   - **特点**：比 `std::list` 更轻量，适用于不需要双向访问的场景。

这些容器各有优劣，选择合适的容器可以帮助提高程序的效率和可维护性。