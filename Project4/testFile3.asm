LOAD 0
STORE p1
READ p2
LOAD 0
STORE p3
LOAD 4 
STORE T1
BRZNEG Done
Repeat4: WRITE T1
SUB 1
BRPOS Repeat4 
Done: NOOP
LOAD p2
MULT -1
STORE p2
WRITE p2
LOAD p3
WRITE p3
WRITE p3
STOP
p1 0
p2 0
p3 0
T1 0
T2 0
