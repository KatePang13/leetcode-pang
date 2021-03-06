/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
    if t1 == nil && t2 == nil {
        return nil
    }

    val := 0
    var t1l *TreeNode = nil
    var t1r *TreeNode = nil
    var t2l *TreeNode = nil
    var t2r *TreeNode = nil

    if t1 != nil {
        val += t1.Val
        t1l = t1.Left
        t1r = t1.Right
    } 
    if t2 != nil {
        val += t2.Val
        t2l = t2.Left
        t2r = t2.Right
    }

    root := &TreeNode{Val: val}
    root.Left = mergeTrees(t1l, t2l)
    root.Right = mergeTrees(t1r, t2r)
    return root
}