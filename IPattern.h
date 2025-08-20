#pragma once

class IPattern
{
	public:
		virtual ~IPattern() = default;

		virtual void setPattern(int v) = 0;
		virtual int getPattern() const = 0;

};

//class IItem {
//public:
//	virtual void update() PURE;
//};
//
//class ItemRecover
//	: public IItem
//{
//	void enforce() override
//	{
//		player.setSiheld(player.getShield() + 1);
//		player.addShield( 1 );
//	}
//};
//
//class ItemSpeedUp
//	: public IItem
//{
//	void enforce() override
//	{
//		player.setVX(player.getVX() + 1);
//		player.setVY(player.getVY() + 1);
//	}
//};
//
//class ItemManager
//{
//public:
//	void update()
//	{
//		items.for_each([](IItem& item) {
//			if (hitcheck(player)) {
//				switch (item.getPatten())
//				{
//				case ItemType::RECOVER:
//					Recover(player);
//					break;
//				case ItemType::SPEED_UP:
//					player.setVX(player.getVX() + 1);
//					player.setVY(player.getVY() + 1);
//					break;
//				}
//
//				// item.enforce(player);
//			}
//		});
//	}
//private:
//	std::array<Item, 10> items;
//};