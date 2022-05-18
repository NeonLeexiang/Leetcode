/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
class RandomizedSet {
public:
    // 用于存储对应的数据，我们直接 push_back 从末尾添加，
    // 当我们需要删除一个数据的时候，我们只需要将其和尾部的数据进行交换即可，然后修改索引hash
    // 所有的内容都是为了 getRandom 的时候可以在O(1)得到
    // 因为当数组紧凑的时候我们可以直接生成随机数索引进行获取
    vector<int> nums;
    
    // 记录每个元素对应在 nums 的索引
    unordered_map<int, int> val2index;

    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (val2index.count(val)) return false;
        val2index[val] = nums.size();
        nums.push_back(val);
        return true;
    }   
    
    bool remove(int val) {
        // 先把要删除的元素放至末尾，这样就可以直接 pop_back 即可
        // 值得注意的是需要记得删除 map 中对应的 val index 索引
        if (!val2index.count(val)) return false;

        // 交换元素，并修改对应索引
        int index = val2index[val];
        val2index[nums.back()] = index;
        int temp = nums[index];
        nums[index] = nums.back();
        nums.back() = val;

        nums.pop_back();
        val2index.erase(val);

        return true;
    }
    
    int getRandom() {
        return nums[rand()% nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

