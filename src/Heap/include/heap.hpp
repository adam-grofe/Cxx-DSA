
#pragma once
#include <vector>

namespace Heap
{

    template <typename PriorityT, typename ValueT>
    struct Node
    {
        PriorityT priority;
        ValueT value;
    };

    template <typename PriorityT, typename ValueT>
    class MaxHeap
    {
    public:
        MaxHeap(size_t branchingFactor = 4): _branchingFactor(branchingFactor)
        {
            _data = std::vector<Node<PriorityT, ValueT>>{};
            if( _branchingFactor < 2)
                throw std::runtime_error("Branching factor should not be less than 2.");
        };

        void insert(PriorityT priority, ValueT value)
        {
            Node<PriorityT, ValueT> newNode;
            newNode.priority = priority;
            newNode.value = value;
            _data.push_back(newNode);
            _bubble_up(size() - 1);
        };

        ValueT top()
        {
            ValueT node = _data[0].value;
            size_t last = size() - 1;
            _swap(0, last);
            _data.pop_back();
            if (size() > 1)
                _push_down(0);
            return node;
        };

        size_t size() { return _data.size(); };

    private:
        std::vector<Node<PriorityT, ValueT>> _data;
        const size_t _branchingFactor;

        constexpr size_t _null() { return size_t(0) - 1; };

        bool _is_null(size_t index) { return index == _null(); };

        void _swap(size_t left, size_t right)
        {
            if (left == right)
                return;
            auto temp = _data[left];
            _data[left] = _data[right];
            _data[right] = temp;
        }

        size_t _get_parent_index(size_t index)
        {
            if (index <= 1)
            {
                return 0;
            }
            return (index - 1) / _branchingFactor;
        }

        size_t _get_children_index(size_t index)
        {
            return _branchingFactor * index + 1;
        }

        size_t _get_max_child(size_t index)
        {
            size_t child_start = _get_children_index(index);
            if (child_start > size() - 1)
            {
                return _null();
            }
            size_t max_child = child_start;
            for (size_t i = 0; i < _branchingFactor; i++)
            {
                size_t index = child_start + i;
                if (index > _data.size() - 1)
                {
                    break;
                }

                if (_data[index].priority > _data[max_child].priority)
                {
                    max_child = index;
                }
            }
            return max_child;
        }

        void _bubble_up(size_t index)
        {
            size_t current_index = index;
            while (current_index > 0)
            {
                size_t parent_index = _get_parent_index(current_index);
                if (_data[current_index].priority > _data[parent_index].priority)
                {
                    _swap(current_index, parent_index);
                }
                current_index = parent_index;
            }
        }

        void _push_down(size_t index)
        {
            size_t current_index = index;
            while (current_index < size() - 1)
            {
                size_t max_child = _get_max_child(current_index);

                if (_is_null(max_child))
                    break;

                if (_data[current_index].priority < _data[max_child].priority)
                {
                    _swap(current_index, max_child);
                }
                else
                {
                    break;
                }
                current_index = max_child;
            }
        }
    };
}