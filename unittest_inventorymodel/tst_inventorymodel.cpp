#include <QtTest>
#include <QSignalSpy>
#include "InventoryModel.h"  // Adjust the include path as necessary

// Utility: Create a CoffeeRecipe for testing.
static CoffeeRecipe createRecipe(int beans, int water, int cups, int milk) {
    CoffeeRecipe recipe;
    recipe.coffeeBeansRequired = beans;
    recipe.waterRequired = water;
    recipe.cupsRequired = cups;
    recipe.milkRequired = milk;
    return recipe;
}

class inventory_model_test : public QObject
{
    Q_OBJECT

public:
    inventory_model_test();
    ~inventory_model_test();

private slots:
    void initTestCase();
    void cleanupTestCase();

    // Basic tests for hasSufficientResources and updateResources
    void test_hasSufficientResources();
    void test_updateResources_sufficient();
    void test_updateResources_insufficient();

    // Edge: Update when resources exactly match recipe requirements.
    void test_updateResources_exactMatch();

    // Edge: Multiple sequential updates until resources run out.
    void test_multipleSequentialUpdates();

    // Refill functions: normal, zero, and negative refill.
    void test_refillCoffeeBeans();
    void test_refillWater();
    void test_refillCups();
    void test_refillMilk();
    void test_refillZeroAmount();
    void test_negativeRefill();

    // Test getters consistency after various operations.
    void test_getters();
};

inventory_model_test::inventory_model_test() {}
inventory_model_test::~inventory_model_test() {}

void inventory_model_test::initTestCase()
{
    // Global initialization if needed.
}

void inventory_model_test::cleanupTestCase()
{
    // Global cleanup if needed.
}

// Test hasSufficientResources for both sufficient and insufficient conditions.
void inventory_model_test::test_hasSufficientResources()
{
    InventoryModel model;

    // Recipe that should be affordable with the initial resources.
    CoffeeRecipe recipeOk = createRecipe(5, 50, 1, 10);
    QVERIFY(model.hasSufficientResources(recipeOk));

    // Recipes exceeding each resource.
    CoffeeRecipe recipeFail = createRecipe(model.getCoffeeBeans() + 1, 0, 0, 0);
    QVERIFY(!model.hasSufficientResources(recipeFail));

    recipeFail = createRecipe(0, model.getWaterLevel() + 1, 0, 0);
    QVERIFY(!model.hasSufficientResources(recipeFail));

    recipeFail = createRecipe(0, 0, model.getCups() + 1, 0);
    QVERIFY(!model.hasSufficientResources(recipeFail));

    recipeFail = createRecipe(0, 0, 0, model.getMilk() + 1);
    QVERIFY(!model.hasSufficientResources(recipeFail));
}

// Test updateResources when resources are sufficient.
void inventory_model_test::test_updateResources_sufficient()
{
    InventoryModel model;
    QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));

    CoffeeRecipe recipe = createRecipe(10, 100, 1, 20);

    int initBeans = model.getCoffeeBeans();
    int initWater = model.getWaterLevel();
    int initCups  = model.getCups();
    int initMilk  = model.getMilk();

    QVERIFY(model.hasSufficientResources(recipe));

    model.updateResources(recipe);

    QCOMPARE(spy.count(), 1);
    QCOMPARE(model.getCoffeeBeans(), initBeans - recipe.coffeeBeansRequired);
    QCOMPARE(model.getWaterLevel(), initWater - recipe.waterRequired);
    QCOMPARE(model.getCups(), initCups - recipe.cupsRequired);
    QCOMPARE(model.getMilk(), initMilk - recipe.milkRequired);
}

// Test updateResources when resources are insufficient (inventory should remain unchanged).
void inventory_model_test::test_updateResources_insufficient()
{
    InventoryModel model;
    QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));

    CoffeeRecipe recipe = createRecipe(0, 0, model.getCups() + 1, 0);
    QVERIFY(!model.hasSufficientResources(recipe));

    int beansBefore = model.getCoffeeBeans();
    int waterBefore = model.getWaterLevel();
    int cupsBefore  = model.getCups();
    int milkBefore  = model.getMilk();

    model.updateResources(recipe);

    QCOMPARE(spy.count(), 0);
    QCOMPARE(model.getCoffeeBeans(), beansBefore);
    QCOMPARE(model.getWaterLevel(), waterBefore);
    QCOMPARE(model.getCups(), cupsBefore);
    QCOMPARE(model.getMilk(), milkBefore);
}

// Test updateResources when available resources exactly match the recipe requirements.
void inventory_model_test::test_updateResources_exactMatch()
{
    // Create an InventoryModel with custom values.
    InventoryModel model;
    // Create a recipe that exactly matches current resources.
    CoffeeRecipe recipe;
    recipe.coffeeBeansRequired = model.getCoffeeBeans();
    recipe.waterRequired       = model.getWaterLevel();
    recipe.cupsRequired        = model.getCups();
    recipe.milkRequired        = model.getMilk();

    QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));
    QVERIFY(model.hasSufficientResources(recipe));

    model.updateResources(recipe);
    QCOMPARE(spy.count(), 1);

    // All resources should now be zero.
    QCOMPARE(model.getCoffeeBeans(), 0);
    QCOMPARE(model.getWaterLevel(), 0);
    QCOMPARE(model.getCups(), 0);
    QCOMPARE(model.getMilk(), 0);
}

// Test performing multiple sequential updates until resources run out.
void inventory_model_test::test_multipleSequentialUpdates()
{
    InventoryModel model;
    // Use a small recipe so we can update multiple times.
    CoffeeRecipe recipe = createRecipe(1, 10, 1, 2);

    // Count how many times we can update until one resource runs out.
    int count = 0;
    while (model.hasSufficientResources(recipe)) {
        QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));
        model.updateResources(recipe);
        // Verify signal emission per update.
        QCOMPARE(spy.count(), 1);
        ++count;
    }

    // After loop, at least one resource must be insufficient.
    QVERIFY(!model.hasSufficientResources(recipe));

    // Check that each resource is not negative.
    QVERIFY(model.getCoffeeBeans() >= 0);
    QVERIFY(model.getWaterLevel() >= 0);
    QVERIFY(model.getCups() >= 0);
    QVERIFY(model.getMilk() >= 0);

    // Just print out how many times the update occurred.
    qDebug() << "Performed" << count << "sequential updates until resources were insufficient.";
}

// Test refillCoffeeBeans increases the beans count and emits inventoryUpdated.
void inventory_model_test::test_refillCoffeeBeans()
{
    InventoryModel model;
    QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));

    int beansBefore = model.getCoffeeBeans();
    int refillAmount = 15;
    model.refillCoffeeBeans(refillAmount);

    QCOMPARE(model.getCoffeeBeans(), beansBefore + refillAmount);
    QCOMPARE(spy.count(), 1);
}

// Test refillWater increases the water level and emits inventoryUpdated.
void inventory_model_test::test_refillWater()
{
    InventoryModel model;
    QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));

    int waterBefore = model.getWaterLevel();
    int refillAmount = 200; // in ml
    model.refillWater(refillAmount);

    QCOMPARE(model.getWaterLevel(), waterBefore + refillAmount);
    QCOMPARE(spy.count(), 1);
}

// Test refillCups increases the cups count and emits inventoryUpdated.
void inventory_model_test::test_refillCups()
{
    InventoryModel model;
    QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));

    int cupsBefore = model.getCups();
    int refillAmount = 5;
    model.refillCups(refillAmount);

    QCOMPARE(model.getCups(), cupsBefore + refillAmount);
    QCOMPARE(spy.count(), 1);
}

// Test refillMilk increases the milk level and emits inventoryUpdated.
void inventory_model_test::test_refillMilk()
{
    InventoryModel model;
    QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));

    int milkBefore = model.getMilk();
    int refillAmount = 50;
    model.refillMilk(refillAmount);

    QCOMPARE(model.getMilk(), milkBefore + refillAmount);
    QCOMPARE(spy.count(), 1);
}

// Test refilling with a zero amount should still emit the signal (if that is desired)
// but not change the inventory.
void inventory_model_test::test_refillZeroAmount()
{
    InventoryModel model;
    QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));

    int beansBefore = model.getCoffeeBeans();
    model.refillCoffeeBeans(0);
    QCOMPARE(model.getCoffeeBeans(), beansBefore);
    // Depending on your design, a zero refill might still emit a signal.
    QCOMPARE(spy.count(), 1);
}

// Test negative refill values. Note: The current implementation does not guard against negatives,
// so a negative refill will reduce the inventory.
void inventory_model_test::test_negativeRefill()
{
    InventoryModel model;
    QSignalSpy spy(&model, SIGNAL(inventoryUpdated()));

    int waterBefore = model.getWaterLevel();
    int negativeAmount = -50;
    model.refillWater(negativeAmount);
    // Expect the water level to decrease.
    QCOMPARE(model.getWaterLevel(), waterBefore + negativeAmount);
    QCOMPARE(spy.count(), 1);
}

// Test that the getters reflect the current inventory after a series of operations.
void inventory_model_test::test_getters()
{
    InventoryModel model;

    int beansInitial = model.getCoffeeBeans();
    int waterInitial = model.getWaterLevel();
    int cupsInitial  = model.getCups();
    int milkInitial  = model.getMilk();

    // Perform a series of refill operations.
    model.refillCoffeeBeans(10);
    model.refillWater(100);
    model.refillCups(2);
    model.refillMilk(20);

    QCOMPARE(model.getCoffeeBeans(), beansInitial + 10);
    QCOMPARE(model.getWaterLevel(), waterInitial + 100);
    QCOMPARE(model.getCups(), cupsInitial + 2);
    QCOMPARE(model.getMilk(), milkInitial + 20);
}

QTEST_APPLESS_MAIN(inventory_model_test)
#include "tst_inventorymodel.moc"
