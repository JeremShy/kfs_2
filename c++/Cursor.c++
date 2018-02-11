#include <libk.h>
#include <inline.h>
#include <Cursor.h>

Cursor::Cursor()
{

}

void Cursor::moveCursorTo(int x, int y)
{
	uint16_t pos = y * VGA_WIDTH + x;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

void Cursor::enable(uint8_t startLine, uint8_t endLine)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | startLine);
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3E0) & 0xE0) | endLine);
}

void Cursor::disable()
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}
