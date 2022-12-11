import copy
import random
import time
nums = []
length = 10000
for i in range(length):
    nums.append(random.randint(1, 2000))
nums = [i for i in range(length)]

def show_time(func, *args, **kwargs):
    start = time.perf_counter()
    result = func(*args, **kwargs)
    end = time.perf_counter()
    print(f"{func.__name__}:\n\t结果:{result}\n\t耗时:{end-start}s")
    return end-start

def bubble(nums):
    bubble_nums = copy.copy(nums)
    for i in range(0, length):
        temp_i = 0
        while temp_i + i < length-1:
            if bubble_nums[temp_i] > bubble_nums[temp_i + 1]:
                bubble_nums[temp_i], bubble_nums[temp_i + 1] = bubble_nums[temp_i + 1], bubble_nums[temp_i]
            temp_i+=1
    return bubble_nums

def choice(nums):
    for i in range(length):
        for j in range(i,length):
            if nums[i] > nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
    return nums

def insert(nums):
    length = len(nums)
    for i in range(1,length):
        temp_j = 0
        for j in range(i):
            if nums[j]<nums[i]:
                temp_j += 1
        nums.insert(temp_j, nums[i])
        nums.pop(i+1)
    return nums

def merge(nums):
    def sort_sorted(l1,l2):
        len_l1 = len(l1)
        len_l2 = len(l2)

        i1 = 0
        i2 = 0
        result = []
        while i1 < len_l1 and i2 < len_l2:
            if l1[i1] < l2[i2]:
                result.append(l1[i1])
                i1+=1
            else:
                result.append(l2[i2])
                i2+=1
        if i1 == len_l1:
            result.extend(l2[i2:])
        else:
            result.extend(l1[i1:])
        return result

    def recur_merge(input_nums):
        if len(input_nums) >= 2:
            len_l1 = int(len(input_nums)/2)
            l1 = recur_merge(input_nums[:len_l1])
            l2 = recur_merge(input_nums[len_l1:])
            return sort_sorted(l1,l2)
        else:
            return input_nums
    nums = recur_merge(input_nums=nums)
    return nums
   
def fast(nums):
    def recur(nums):
        if len(nums) <= 1:
            return nums
        base = nums[0:1]
        small = []
        big = []
        result = []
        for num in nums[1:]:
            if num < base[0]:
                small.append(num)
            elif num > base[0]:
                big.append(num)
            else:
                base.append(num)
        small = recur(small)
        big = recur(big)
        result.extend(small)
        result.extend(base)
        result.extend(big)
        return result
    nums = recur(nums)
    return nums

def shell(nums):
    gap = int(len(nums)/2)
    def recur(nums, gap):
        # 使gap间隔的数组保持有序
        gap_nums = nums[::gap]
        gap_nums = insert(gap_nums)
        for i,num in enumerate(gap_nums):
            nums[i*gap] = num
        if gap == 1:
            return nums
        else:
            return recur(nums, int(gap/2))
    nums = recur(nums, gap)
    return nums

if __name__ == '__main__':
    show_time(bubble, nums)
    show_time(choice, nums)
    show_time(insert, nums)
    show_time(merge, nums)
    show_time(fast, nums)
    show_time(shell, nums)