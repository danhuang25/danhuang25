#pragma once
template<typename t>
void sortmoney(t*&a,int &size)
{
	int i, work;
	t temp;
	for (int pass = 1; pass < size; pass++)
	{
		work = 1;
		for (i = 0; i < size - pass; i++)
		{
			if (a[i].money < a[i + 1].money)
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				work = 0;
			}
		}
		if (work)break;
	}
}