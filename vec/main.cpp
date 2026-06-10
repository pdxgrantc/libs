#include <iostream>
#include <string>
#include "vec.h"
#include "obj.h"
//#include "helper.h"

using namespace std;

void vec_int_test(int, int);
void vec_string_test(int);
void vec_obj_test(int, Vec<Obj> *);
void vec_op_overload();
void obj_print(Obj object);
void obj_ptr_print(Obj *object);

int main()
{
    int num = 5;
    for (int i = 2; i < num; i++)
    {
        vec_int_test(i, 0);
    }

    vec_string_test(0);
    vec_op_overload();

    Vec<Obj> *obj = new Vec<Obj>;

    vec_obj_test(0, obj);

    obj->print_vec_obj(obj_print);

    delete obj;

    return 0;
}

void vec_int_test(int len, int print)
{
    Vec<int> nums;

    for (int i = 0; i < len; i++)
    {
        nums.push(i);
    }

    nums.insert(len - 2, 15);

    // return if print is 0
    if (!print)
        return;
    for (int i = 0; i < nums.getLen(); i++)
    {
        cout << nums.get(i) << " ";
    }
    cout << endl;
}

void vec_string_test(int print)
{
    Vec<string> *strs = new Vec<string>;

    strs->push("Hello");
    strs->push("World");
    strs->push("This");
    strs->push("is");
    strs->push("terrible");
    strs->push("now");

    if (!print)
    {
        delete strs;
        return;
    }

    for (int i = 0; i < strs->getLen(); i++)
    {
        cout << strs->get(i) << " ";
    }
    cout << endl;

    delete strs;
}

void vec_op_overload()
{
    int len = 5;
    Vec<int> nums1;

    for (int i = 0; i < len; i++)
    {
        nums1.push(i);
    }

    cout << "nums1: ";
    nums1.print_vec();
    cout << endl;

    Vec<int> nums2 = nums1;

    cout << "nums1: ";
    nums1.print_vec();
    cout << "nums2: ";
    nums2.print_vec();
    cout << endl;

    nums1.insert(len - 2, 15);

    cout << "nums1: ";
    nums1.print_vec();
    cout << "nums2: ";
    nums2.print_vec();
    cout << endl;

    nums2 = nums1;

    cout << "nums1: ";
    nums1.print_vec();
    cout << "nums2: ";
    nums2.print_vec();
    cout << endl;
}

void obj_print(Obj object)
{
    std::cout << "D1: " << object.data1 << " \tD2: " << object.data2 << std::endl;
}

void obj_ptr_print(Obj *object)
{
    std::cout << "D1: " << object->data1 << " D2: " << object->data2 << std::endl;
}

void vec_obj_test(int print, Vec<Obj> *objs4)
{
    int num = 17;
    for (int i = 0; i < num; i++)
    {
        objs4->push(Obj(i, i*2));
    }
}
