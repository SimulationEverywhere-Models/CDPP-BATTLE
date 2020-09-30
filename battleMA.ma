[Top]
components : Knight Dragon

out : battleOut
in : battleIn

Link : battleIn kIn@Knight
Link : kOut@Knight dIn@Dragon
Link : dOut@Dragon kIn@Knight
Link : dOut@Dragon battleOut

[Knight]
components : kdecision@Kdecision kattack@Kattack kmove@Kmove 
out : kOut 
in : kIn 
Link : out@kdecision in@kattack
Link : out@kdecision in@kmove
Link : out@kattack kOut
Link : out@kmove kOut
Link : kIn in@kdecision

[kdecision]

[kattack]

[kmove]

[Dragon]
components : ddecision@Ddecision dattack@Dattack dmove@Dmove 

out : dOut 
in : dIn 

Link : out@ddecision in@dattack
Link : out@ddecision in@dmove
Link : out@dattack dOut
Link : out@dmove dOut
Link : dIn in@ddecision

[ddecision]

[dattack]

[dmove] 
