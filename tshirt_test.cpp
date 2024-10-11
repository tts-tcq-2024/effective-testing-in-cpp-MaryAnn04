#include <gtest/gtest.h>

// Function to determine T-shirt size based on cms input
char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms >= 38 && cms <= 42) {  // Adjust condition to include 38 and 42
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

// Test cases to cover the different sizes and boundary values
TEST(TShirtSizeTest, SmallSize) {
    EXPECT_EQ(size(37), 'S');  // Should return 'S'
}

TEST(TShirtSizeTest, MediumSize) {
    EXPECT_EQ(size(38), 'M');  // Boundary case for size 'M'
    EXPECT_EQ(size(40), 'M');  // Should return 'M'
    EXPECT_EQ(size(42), 'M');  // Boundary case for size 'M'
}

TEST(TShirtSizeTest, LargeSize) {
    EXPECT_EQ(size(43), 'L');  // Should return 'L'
}

TEST(TShirtSizeTest, OutOfBoundsTest) {
    EXPECT_EQ(size(38), 'M');  // Check the lower boundary of 'M'
    EXPECT_EQ(size(42), 'M');  // Check the upper boundary of 'M'
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
