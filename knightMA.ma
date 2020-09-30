[Top]
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


