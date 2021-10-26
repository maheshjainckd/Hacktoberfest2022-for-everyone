var app = angular.module("myShoppingList", []);
app.controller("myCtrl", function ($scope) {
  $scope.products = [];
  $scope.addItem = function () {
    $scope.errortext = "";
    if (!$scope.addMe) {
      return;
    }
    if ($scope.products.indexOf($scope.addMe) == -1) {
      $scope.products.push($scope.addMe);
    } else {
      $scope.errortext = "This item is already in your Todo List.";
    }
  };
  $scope.removeItem = function (x) {
    $scope.products.splice(x, 1);
  };
});
