/* You should implement rest of data from quiz in p89 */
DATA CHAP_2_Q_6_DATA_1;
	INFILE '/folders/myfolders/Quiz/CHAP2_Q_6_score1.txt';
	INPUT ID NAME $ KOREAN ENGLISH MATH;
RUN;

DATA CHAP_2_Q_6_DATA_2;
	INFILE '/folders/myfolders/Quiz/CHAP2_Q_6_score2.txt';
	INPUT ID NAME $ SOCIAL SCIENCE;
RUN;

DATA CHAP_2_Q_6_DATA;
	MERGE CHAP_2_Q_6_DATA_1 CHAP_2_Q_6_DATA_2;
	BY ID;
RUN;

PROC PRINT DATA=CHAP_2_Q_6_DATA;
RUN;