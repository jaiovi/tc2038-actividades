class QuickSort:
    @classmethod
    def sort(cls, array, low, high):
        if low < high:
            pivot = cls.__partition(array, low, high)
            cls.sort(array, low, pivot - 1)
            cls.sort(array, pivot + 1, high)
    @classmethod
    def __swap(cls, array, i, j):
        array[i], array[j] = array[j], array[i]

    @classmethod
    def __partition(cls, array, low, high):
        pivot_value = array[low].get_objective_value()
        j = low
        i = low + 1
        while i <= high:
            if array[i].get_objective_value() < pivot_value:
                j = j + 1
                cls.__swap(array, i, j)
            i = i + 1
        pivot = j
        cls.__swap(array, low, pivot)
        return pivot