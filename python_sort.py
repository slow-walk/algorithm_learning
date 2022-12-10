import copy
import random
nums = []
length = 10000
for i in range(length):
    nums.append(random.randint(1, 100000))

def bubble(nums):
    start = time.perf_counter()
    bubble_nums = copy.copy(nums)
    for i in range(0, length):
        temp_i = 0
        while temp_i + i < length-1:
            if bubble_nums[temp_i] > bubble_nums[temp_i + 1]:
                bubble_nums[temp_i], bubble_nums[temp_i + 1] = bubble_nums[temp_i + 1], bubble_nums[temp_i]
            temp_i+=1
    end = time.perf_counter()
    print(bubble_nums, f"\nbubble消耗时间：{end-start}s")

def choice(nums):
    start = time.perf_counter()
    for i in range(length):
        for j in range(i,length):
            if nums[i] > nums[j]:
                nums[i], nums[j] = nums[j], nums[i]
    end = time.perf_counter()
    print(nums, f"\nchoice消耗时间：{end-start}s")

def insert(nums):
    start = time.perf_counter()
    for i in range(1,length):
        temp_j = 0
        for j in range(i):
            if nums[j]<nums[i]:
                temp_j += 1
        nums.insert(temp_j, nums[i])
        nums.pop(i+1)
    end = time.perf_counter()
    print(nums, f"\ninsert消耗时间：{end-start}s")

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
    start = time.perf_counter()
    nums = recur_merge(input_nums=nums)
    end = time.perf_counter()

    print(nums, f"\nmerge消耗的时间为{end-start}s")
if __name__ == '__main__':
    bubble(nums)
    choice(nums)
    insert(nums)
    merge(nums)
