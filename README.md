ㄧ、
void swap()是用來交換兩個int array的位置
int part()則是quicksort最重要的一部分，也就是在選擇pivot後，將其餘的integer分倒pivot兩邊
	裡頭的for迴圈會利用swap的方式將小於pivot的數字移到array前頭
void quick_sort()是用來做遞迴的，如已做到不需排列時則會停止
	選好pivot且排列好之後，會對pivot之前和之後的數字再進行quicksort
int main 可以進行input並計算總共有幾個integer需要排列，排列完後會用for迴圈來輸出sort好的數字

二、
與一做法一樣但新增了一個int mid()
可從array最前、最後、中位數選出中間的值做pivot

三、
與一做法一樣但新增了一個int mid() 和int choose()
利用mid可以找到pivot
用while迴圈裡呼叫choose的方式找到pivot
choose的做法和mid的做法一樣選出三個值得最中間值是用if來做

 [StackEdit](https://stackedit.io/).