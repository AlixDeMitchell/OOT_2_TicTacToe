#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <list>


struct StateNode
{
	enum GameState
	{
		PLAYING,
		XWIN,
		OWIN,
		DRAW
	};

	GameState currentState;

	bool lastPlayerWasX = false;
	double score;
	StateNode() { currentState = PLAYING; score = 0; };
	StateNode( double _score ) { score = _score; }
	std::string board;
	std::vector<StateNode*> children;

	//std::vector <StateNode*> children;
};

void CheckWin( StateNode* _root );
void MiniMaxTree( StateNode* _root );//std::shared_ptr < StateNode >& _root );
double SetTreeValue( StateNode* _root );

int main( void )
{
	/*StateNode tempNode;
	std::shared_ptr < StateNode > root = std::make_shared < StateNode > ( tempNode );*/

	StateNode* root = new StateNode;
	bool isPlayerTurn = true;
	bool win = false;
	//int xCount = 0;
	//int oCount = 0;

	root->board = "         ";
	MiniMaxTree( root );
	SetTreeValue( root );


	while ( root->currentState == StateNode::PLAYING )
	{
		if ( isPlayerTurn )
		{
			int temp = 0; //player input
			std::string tempstr = root->board;

			std::cout << "Input your thing" << std::endl;
			std::cin >> temp;

			tempstr.at( temp ) = 'X';

			for ( size_t i = 0; i < root->children.size(); i++ )
			{
				if ( root->children.at( i )->board == tempstr )
				{
					root = root->children.at( i );
				}
			}

			isPlayerTurn = false;
		}

		else 
		{
			StateNode* tempNode;
			tempNode = root->children.at( 0 );

			for ( size_t i = 0; i < root->children.size(); i++ )
			{
				if ( root->children.at( i )->score > tempNode->score )
				{
					tempNode = root->children.at( i );

				}
			}
			root = tempNode;
			isPlayerTurn = true;
		}

		//set current node
		//display current node
		//change bool
	}

	system( "PAUSE" );
	return 0;
}

void CheckWin( StateNode* _root )
{
	StateNode::GameState stateToReturn = StateNode::DRAW;
	int multiplier = 1;

	for ( size_t i = 0; i < 9; i++ )
	{
		if ( _root->board.at( i ) == ' ' )
		{
			stateToReturn = StateNode::PLAYING;
			multiplier *= 10;
		}
	}

	//check rows
	if ( _root->board.at( 0 ) == _root->board.at( 1 ) && _root->board.at( 1 ) == _root->board.at( 2 ) )
	{
		if ( _root->board.at( 0 ) == 'X' )
		{
			std::cout << "X wins";
			stateToReturn = StateNode::XWIN;
		}
		else if ( _root->board.at( 0 ) == 'O' )
		{
			std::cout << "O wins";
			stateToReturn = StateNode::OWIN;
		}
	}//close row if

	if ( _root->board.at( 3 ) == _root->board.at( 4 ) && _root->board.at( 4 ) == _root->board.at( 5 ) )
	{
		if ( _root->board.at( 3 ) == 'X' )
		{
			std::cout << "X wins";
			stateToReturn = StateNode::XWIN;
		}

		else if ( _root->board.at( 3 ) == 'O' )
		{
			std::cout << "O wins";
			stateToReturn = StateNode::OWIN;
		}
	}//close row if

	if ( _root->board.at( 6 ) == _root->board.at( 7 ) && _root->board.at( 7 ) == _root->board.at( 8 ) )
	{
		if ( _root->board.at( 6 ) == 'X' )
		{
			std::cout << "X wins";
			stateToReturn = StateNode::XWIN;
		}

		else if ( _root->board.at( 6 ) == 'O' )
		{
			std::cout << "O wins";
			stateToReturn = StateNode::OWIN;
		}
	}//close row if

	 //check columns
	if ( _root->board.at( 0 ) == _root->board.at( 3 ) && _root->board.at( 3 ) == _root->board.at( 6 ) )
	{
		if ( _root->board.at( 0 ) == 'X' )
		{
			std::cout << "X wins";
			stateToReturn = StateNode::XWIN;
		}

		else if ( _root->board.at( 0 ) == 'O' )
		{
			std::cout << "O wins";
			stateToReturn = StateNode::OWIN;
		}
	}//close column if

	 //check columns
	if ( _root->board.at( 1 ) == _root->board.at( 4 ) && _root->board.at( 4 ) == _root->board.at( 7 ) )
	{
		if ( _root->board.at( 1 ) == 'X' )
		{
			std::cout << "X wins";
			stateToReturn = StateNode::XWIN;
		}

		else if ( _root->board.at( 1 ) == 'O' )
		{
			std::cout << "O wins";
			stateToReturn = StateNode::OWIN;
		}
	}//close column if

	 //check columns
	if ( _root->board.at( 2 ) == _root->board.at( 5 ) && _root->board.at( 5 ) == _root->board.at( 8 ) )
	{
		if ( _root->board.at( 2 ) == 'X' )
		{
			std::cout << "X wins";
			stateToReturn = StateNode::XWIN;
		}

		else if ( _root->board.at( 2 ) == 'O' )
		{
			std::cout << "O wins";
			stateToReturn = StateNode::OWIN;
		}
	}//close column if

	//check diagonals
	if ( _root->board.at( 0 ) == _root->board.at( 4 ) && _root->board.at( 4 ) == _root->board.at( 8 ) )
	{
		if ( _root->board.at( 0 ) == 'X' )
		{
			std::cout << "X wins";
			stateToReturn = StateNode::XWIN;
		}

		else if ( _root->board.at( 0 ) == 'O' )
		{
			std::cout << "O wins";
			stateToReturn = StateNode::OWIN;
		}
	}//close diagonal if

	 //check diagonals
	if ( _root->board.at( 2 ) == _root->board.at( 4 ) && _root->board.at( 4 ) == _root->board.at( 6 ) )
	{
		if ( _root->board.at( 2 ) == 'X' )
		{
			std::cout << "X wins";
			stateToReturn = StateNode::XWIN;
		}

		else if ( _root->board.at( 2 ) == 'O' )
		{
			std::cout << "O wins";
			stateToReturn = StateNode::OWIN;
		}
	}//close diagonal if

	_root->currentState = stateToReturn;

	switch ( _root->currentState )
	{
	case StateNode::DRAW:
		_root->score = -1 * multiplier;
		break;
	case StateNode::OWIN:
		_root->score = 2 * multiplier;
		break;
	case StateNode::XWIN:
		_root->score = -2 * multiplier;
		break;
	default:
		break;
	}

}

void MiniMaxTree( StateNode* _root ) //std::shared_ptr < StateNode >& _root ) //, bool _player, int _xCount, int _oCount )
{
	//figure out whose turn it is based on number of x and o on the board already
	//if (  )
	//{
		//_player = false; //it's o's turn if there are more x's on the board already

	if ( _root->currentState == StateNode::PLAYING )
	{
		for ( int i = 0; i < 9; i++ )//go through each space in the string
		{
			//StateNode temp;
			//std::shared_ptr < StateNode > newNode;
			//newNode = std::make_shared< StateNode >( temp ); //create a new node each time, filling in spaces with Os
			//newNode->board = _root->board;

			StateNode* newNode = new StateNode;
			newNode->board = _root->board;

			if ( newNode->board.at( i ) == ' ' )
			{
				if ( _root->lastPlayerWasX == false )
				{
					newNode->board.at( i ) = 'X';
					newNode->lastPlayerWasX = true;
				}

				else
				{
					newNode->board.at( i ) = 'O';
					newNode->lastPlayerWasX = false;
				}

				CheckWin( newNode );

				_root->children.push_back( newNode ); //std::make_shared < StateNode >( newNode ) );

				MiniMaxTree( newNode );//std::make_shared < StateNode >( newNode ) );//recurse
			}
		}
	}
}

double SetTreeValue( StateNode* _root )
{
	double value = 0;

	for ( size_t i = 0; i < _root->children.size(); i++ )
	{
		value = SetTreeValue( _root->children.at( i ) );
		_root->score += value;
	}

	return _root->score;
}
