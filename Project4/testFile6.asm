LOAD 0
STORE prog4
READ prog5
LOAD 0
STORE zd2
LOAD 5
STORE T1
LOAD prog5
SUB T1
BRNEG Done
LOAD zd2
SUB 1
STORE zd2
Done: NOOP
WRITE prog5
WRITE prog4
WRITE zd2
STOP
prog4 0
prog5 0
zd2 0
T1 0
T2 0