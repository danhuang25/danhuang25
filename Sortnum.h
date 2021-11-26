#pragma once
template<typename t>
void sortnum(t*& a, int& size)
{
	int i, work;
	t temp;
	for (int pass = 1; pass < size; pass++)
	{
		work = 1;
		for (i = 0; i < size - pass; i++)
		{
			if (a[i].repertory < a[i + 1].repertory)
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
