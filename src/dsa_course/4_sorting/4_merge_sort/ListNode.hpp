class ListNode
{
public:
    ListNode() : m_Val{0}, m_Next{nullptr}
    {
    };

    ListNode(int val) : m_Val{val}, m_Next{nullptr}
    {
    };

    ListNode(int val, ListNode* node) : m_Val{val}, m_Next{node}
    {
    };

    ListNode* GetNext()
    {
        return m_Next;
    }

    void SetNext(ListNode* node)
    {
        m_Next = node;
    }

    int GetVal()
    {
        return m_Val;
    }

    void SetVal(int val)
    {
        m_Val = val;
    }
private:
    int m_Val;
    ListNode* m_Next;
};