++++++++[>++++++++<-]+++++ +++++.>--. //new line and next

>>+++ +++[<++++ +++>-]<++++ //dot

>>+++ +++[<++++ +++>-]<+ //plus

>+ // move to input/active and add one

[, //start loop and get input from buffer
[<.>-] //print plus with each subtraction from input 
<<. //print dot
<.  //print next
<.  //print new line
>>>>
+] //infinite loop unless user somehow enters max value and there will be overflow