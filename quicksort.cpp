void partition(int& arr, int low, int high){
    int pivot = arr[low];

    int i = low, j = high;
    
    while(i < j){

        do{
            i++;
        } while(i <= high && arr[i] < pivot)

        do{
            j++;
        } while(arr[i] > pivot)

        if(i < j){
            swap(arr[i], arr[j]);
        }

    }

    swap(arr[j], arr[low]);
    return j;

}

void quicksort(int& arr, int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot);
        quicksort(arr, pivot + 1, high);
    }
}

