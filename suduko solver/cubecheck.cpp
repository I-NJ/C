if(r<3&&c<3)
	{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	}

else if(r<3&&c>2&&c<6)
	{
	for(int i=0;i<3;i++)
	{
		for(int j=3;j<6;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	}

else if(r<3&&c>5)
	{
	for(int i=0;i<3;i++)
	{
		for(int j=6;j<9;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	}

else if(r>2&&r<6&&c<3)
	{
	for(int i=3;i<6;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	}

else if(r>2&&r<6&&c>2&&c<6)
	{
	for(int i=3;i<6;i++)
	{
		for(int j=3;j<6;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	}

else if(r>2&&r<6&&c>5)
	{
	for(int i=3;i<6;i++)
	{
		for(int j=6;j<9;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	}
else if(r>5&&c<3)
	{
	for(int i=6;i<9;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	}
	
else if(r>5&&c>2&&c<6)
	{
	for(int i=6;i<9;i++)
	{
		for(int j=3;j<6;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	}
	
else if(r>5&&c>5)
	{
	for(int i=6;i<9;i++)
	{
		for(int j=6;j<9;j++)
		{
			for(int k=0;k<9;k++)
			{
				if(s[i][j]==k+1)
				ans[k]=1;
			}
		}
	}
	}
