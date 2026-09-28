Deadlock Detection using DFS : 



Files:


20230104058.cpp
20230104058.exe
20230104058_Assignemtn02.docx
input_no_deadlock.txt
input_multiple_cycles.txt

How To Run: 


Run the 20230104058.cpp File.

In the terminal paste the sample inputs.

For example if we paste the inputs from input_multiple_cycles.txt 

6 7
0 1
1 2
2 0
2 3
3 4
4 2
4 5


Sample  Terminal View: 





PS C:\6th semester lab\Os Lab 2\Project> cd "c:\6th semester lab\Os Lab 2\Project\" ; if ($?) { g++ DFS.cpp -o DFS } ; if ($?) { .\DFS }
6 7
0 1
1 2
2 0
2 3
3 4
4 2
4 5
Graph:
0 -> 1 
1 -> 2 
2 -> 0 3 
3 -> 4 
4 -> 2 5 
5 -> 

Deadlock Cycles:
Cycle 1: 0 -> 1 -> 2 -> 0
Cycle 2: 2 -> 3 -> 4 -> 2
PS C:\6th semester lab\Os Lab 2\Project> 
