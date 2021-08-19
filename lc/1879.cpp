class Solution
{
public:
    TreeNode *canMerge(vector<TreeNode *> &trees)
    {
        unordered_map<int, int> frequency;
        stack<TreeNode *> treestack;

        for (auto &tree : trees)
        {
            treestack.push(tree);
            while (treestack.size())
            {
                TreeNode *node = treestack.top();
                treestack.pop();
                if (node)
                {
                    ++frequency[node->val];
                    treestack.push(node->left);
                    treestack.push(node->right);
                }
            }
        }

        int cnt = 0;
        TreeNode *root = NULL;
        unordered_map<int, TreeNode *> mp;

        for (auto &tree : trees)
        {
            mp[tree->val] = tree;
            if (frequency[tree->val] & 1)
            {
                ++cnt;
                root = tree;
            }
        }

        if (cnt != 1)
            return NULL;

        treestack.push(root);
        int total = trees.size();
        while (treestack.size())
        {
            TreeNode *node = treestack.top();
            treestack.pop();
            if (node->left && !node->left->left && !node->left->right && mp.count(node->left->val))
            {
                node->left = mp[node->left->val];
                total--;
            }
            if (node->right && !node->right->left && !node->right->right && mp.count(node->right->val))
            {
                node->right = mp[node->right->val];
                total--;
            }
            if (node->left)
                treestack.push(node->left);
            if (node->right)
                treestack.push(node->right);
        }

        if (total != 1)
            return NULL;

        int prev = INT_MIN;
        TreeNode *node = root;
        while (treestack.size() || node)
        {
            if (node)
            {
                treestack.push(node);
                node = node->left;
            }
            else
            {
                node = treestack.top();
                treestack.pop();
                if (prev >= node->val)
                    return NULL;
                prev = node->val;
                node = node->right;
            }
        }
        return root;
    }
};