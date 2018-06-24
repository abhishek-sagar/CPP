#ifndef JOB_H
#define JOB_H

class Job{
public:
	char id;
	int deadline;
	int profit;

	Job(char id,int deadline,int profit){
		this->id = id;
		this->deadline = deadline;
		this->profit = profit;
	}
};

#endif