var TreeNode = (val, left, right) => {
    this.val = (val === undefined ? 0 : val)
    this.left = (left === undefined ? null : left)
    this.right = (right === undefined ? null : right)
}

const levelOrder = (root, lvl, levelSum) => {
    if (!root) {
        return;
    }
    if (lvl >= levelSum.length) {
        levelSum.push(0);
    }

    levelSum[lvl] += root.val;
    levelOrder(root.left, lvl + 1, levelSum);
    levelOrder(root.right, lvl + 1, levelSum);
}

var replaceValueInTree = (root) => {

    let levelSum = []. lvl = 0;
    levelOrder(root, 0, levelSum);
    
    let q = new Queue();
    q.enqueue(root);
    while (!q.isEmpty()) {
        lvl++;
        for (let k = q.size(); k; k--) {

            let r = q.dequeue();
            let sum = r.left?.val ?? 0;
            sum += r.right?.val ?? 0;

            if (r.left) {
                r.left.val = levelSum[lvl] - sum;
                q.enqueue(r.left);
            }
            if (r.right) {
                r.right.val = levelSum[lvl] - sum;
                q.enqueue(r.right);
            }
        }
    }

    root.val = 0;
    return root;
};