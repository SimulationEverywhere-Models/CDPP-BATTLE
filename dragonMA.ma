[Top]
components : ddecision@Ddecision dmove@Dmove dattack@Dattack 
out : dOut 
in : dIn 
Link : dIn in@ddecision
Link : out@ddecision in@dattack
Link : out@dattack dOut
Link : out@ddecision in@dmove
Link : out@dmove dOut

[ddecision]

[dmove]

[dattack]


