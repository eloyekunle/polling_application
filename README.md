Polling
====================
C++ Rating Application

#### Problem Statement
The Internet and the web enable people to network, join a cause, and so on. The
presidential candidates in 2012 used the Internet to get out their messages and raise money. In this
exercise, you’ll write a polling program that allows users to rate five social-consciousness issues from 1
to 10 (most important). Pick five causes (e.g., political issues, global environmental issues). Use a one-
dimensional string array topics to store the causes. To summarize the survey responses, use a 5-row,
10-column two-dimensional array responses (of type int ), each row corresponding to an element in
the topics array . When the program runs, it should ask the user to rate each issue. Have your friends
and family respond to the survey. Then have the program display a summary of the results, including:

a) A tabular report with the five topics down the left side and the 10 ratings across the top, listing in each column the number of ratings received for each topic.

b) To the right of each row, show the average of the ratings for that issue.

c) Which issue received the highest point total? Display both the issue and the point total.

d) Which issue received the lowest point total? Display both the issue and the point total.

Copyright © 2014 Pearson Education, Inc.

####Execution
Follow appropriate compilation instructions for your compiler.

#####Example: Ubuntu 16.04 with cmake

    >> cmake .
    >> make
    >> ./Polling

####Copyright
© 2016 [Oyekunle Elijah PlayMice](http://www.playmiceweb.com/) <elijah@playmiceweb.com>