#include "pch.h"

#include "StringEditCStyle.h"
using namespace std;



/// Chapter1-1
/// ������AHelloWorld!��HelloJapan?�ɕϊ�����B
/// �{�e�X�g���p�X����R�[�h����������B
/// �ϊ�������HelloWorldToHelloJapan()�Ɏ������邱�ƁB
/// HelloWorldToHelloJapan��I/F�i�����E�߂�j�͓K�X�ύX���Ă悢�B
/// ���L�e�X�g�R�[�h�̎w��͈͓͂K�X�ύX���邱�ƁB
/// Input�̕�����HelloWorld!�ł��邱�Ƃ͑O��Ƃ��Ă悢�B
/// C�͈̔͂Ŏ������邱�ƁBC�W�����C�u�����EWin32API�͎g�p�B
TEST(Chapter1, _1_EditStringC) {
	char* helloworld = nullptr;
	{//��������ύX��
		char inStr[] = "HelloWorld!";//�z��̐擪�|�C���^��n���ƁA��O�͔������Ȃ�
		//char inStr = "HelloWorld!";//�|�C���^���ƃA�N�Z�X�ᔽ���������� 
		helloworld = HelloWorldToHelloJapan(inStr);

	}//�����܂ŕύX��

	EXPECT_STREQ(helloworld, "HelloJapan?");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');

	/*
	[�����P]
	EXPECT_EQ�̓|�C���^�̔�r�B�u�A�h���X�v�Ɓu�^�v
	*/
}


/// Chapter1-2
/// ������AHelloWorld!��ByeWorld!�ɕϊ�����B
/// �{�e�X�g���p�X����R�[�h����������B
/// �ϊ�������HelloWorldToByeWorld()�Ɏ������邱�ƁB
/// HelloWorldToByeWorld��I/F�i�����E�߂�j�͓K�X�ύX���Ă悢�B
/// ���L�e�X�g�R�[�h�̎w��͈͓͂K�X�ύX���邱�ƁB
/// Input�̕�����HelloWorld!�ł��邱�Ƃ͑O��Ƃ��Ă悢�B
/// C�͈̔͂Ŏ������邱�ƁBC�W�����C�u�����EWin32API�͎g�p�B
TEST(Chapter1, _2_EditStringC) {
	char* helloworld = nullptr;
	{//��������ύX��
		char inStr[] = "HelloWorld!";
		helloworld = HelloWorldToByeWorld(inStr);
	}//�����܂ŕύX��

	//EXPECT_EQ(helloworld, "ByeWorld!");
	EXPECT_STREQ(helloworld, "ByeWorld!");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}

/// Chapter1-3
/// ������AHelloWorld!��Hello!World!�ɕϊ�����B
/// �{�e�X�g���p�X����R�[�h����������B
/// �ϊ�������HelloWorldToHelloWorld()�Ɏ������邱�ƁB
/// HelloWorldToHelloWorld��I/F�i�����E�߂�j�͓K�X�ύX���Ă悢�B
/// ���L�e�X�g�R�[�h�̎w��͈͓͂K�X�ύX���邱�ƁB
/// Input�̕�����HelloWorld!�ł��邱�Ƃ͑O��Ƃ��Ă悢�B
/// C�͈̔͂Ŏ������邱�ƁBC�W�����C�u�����EWin32API�͎g�p�B
TEST(Chapter1, _3_EditStringC) {
	char* helloworld = nullptr;
	{//��������ύX��
		HelloWorldToHelloJapan(helloworld);
	}//�����܂ŕύX��

	EXPECT_EQ(helloworld, "Hello!World!");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}