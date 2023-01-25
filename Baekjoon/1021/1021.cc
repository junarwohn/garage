#include <iostream>

using namespace std;

typedef struct _node 
{
	int value;
	struct _node * cw;
	struct _node * ccw;
} node;

//class circular queue
class cq 
{
public:
	cq(int N)
	{
		N_ = N;
		node * cq_ = new node;
		cq_->value = 1;	
		cq_->cw = cq_->ccw = cq_;	
		iter_ = cq_;
		for (int i = 2; i < N + 1; i++) 
		{
			node * added_node_ = new node;
			added_node_->value = i;
			added_node_->ccw = iter_;
			added_node_->cw = cq_;
			iter_->cw = added_node_;
			cq_->ccw = added_node_;
			iter_ = added_node_;
		}
		iter_ = cq_;
	}
	void show_cq() 
	{
		node * it = iter_;
		cout << it->value;
		it = it->cw;
		while (it != iter_)
		{
			cout << " -> " << it->value;
			it = it->cw;
		}		
		cout << endl;
	}
	int find_value(int val_) 
	{
	//	show_cq();
		int cnt = 0;
		if (iter_ == NULL) 
		{
	//		cout << "cq is NULL \n";
			return 0;
		} 
		else if (iter_->value == val_) 
		{
			pop();
			return 0;
		} 
		else 
		{
			node * cw_p = iter_;
			node * ccw_p = iter_;
			for (int i = 0; i < N_; i++) 
			{
				cw_p = cw_p->cw;
				ccw_p = ccw_p->ccw;
				cnt++;
				if (cw_p->value == val_) 
				{
					iter_ = cw_p;
				   	break;
				} else if (ccw_p->value == val_) 
				{
					iter_ = ccw_p;
					break;
				}					
			}
	//		cout << "cnt : " << cnt << endl;
			pop();
			return cnt;		
		}
	}
	void pop() 
	{
		if (iter_->cw == iter_) 
		{
			iter_ = NULL;
		}
		else 
		{
			(iter_->ccw)->cw = iter_->cw;
			(iter_->cw)->ccw = iter_->ccw;
			node * tmp = iter_;
			iter_ = iter_->cw;
			delete tmp;
		}
	}
private:
	node * iter_;
	int N_;
};

int main(void) 
{
	int N, M, K;
	int	R = 0;
	cin >> N >> M;
	cq * circular_queue = new cq(N);
	for (int i = 0; i < M; i++)
	{
		cin >> K;
		R += circular_queue->find_value(K);
	}
	cout << R;
	return 0;
}
