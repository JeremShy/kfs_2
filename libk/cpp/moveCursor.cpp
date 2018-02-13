#include <libk.h>

void	moveCursorPrec()
{
	termManager.getActualTerm()->moveCursorPrec();
}

void	moveCursorNext()
{
	termManager.getActualTerm()->moveCursorNext();
}

void	moveCursorUp()
{
	termManager.getActualTerm()->moveCursorUp();
}

void	moveCursorDown()
{
	termManager.getActualTerm()->moveCursorDown();
}
