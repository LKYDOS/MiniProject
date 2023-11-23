<div class="wrap">
    <h1><b>Update Coffee Workshop</b></h1>
    <!-- Workhop name -->
    <h3>Workshop Title:</h3>
        <textarea class = "small-text" rows="1"></textarea>

    <!-- Speakers -->
    <h2>Speaker(s):</h2>
        <textarea class = "small-text"></textarea>

    <!-- Workshop Form -->
    <h2>Form of Workshop</h2>
        <input type="checkbox" name="Physical" value="checkox_value">
        <p style="display: inline-block; margin-left: -3px; margin-right: 5px">Physical</p>

        <input type="checkbox" name="Online" value="checkox_value">
        <p style="display: inline-block; margin-left: -3px; ">Online</p>

    <!-- Duration -->
    <h2>Duration</h2>
        <textarea class="small-text" rows="1" cols="1"></textarea>
        <div class="options-container" id="optionsContainer" style="display: inline-block; vertical-align: top">
        <select>
            <option value="days">hour(s)</option>
            <option value="weeks">day(s)</option>
            <option value="month">week(s)</option>
        </select>
        </div>

    <!-- Quota -->
    <h2>Quota of workshop</h2>
    <textarea class="small-text" rows="1" cols="2"></textarea>

    <!-- Remarks -->
    <h2>Remarks</h2>
    <textarea class="small-text"></textarea>
    <br><br>


    <!-- Confirm -->
  <script>
    function showConfirmation() {
      var result = window.confirm("Are you sure you want to proceed?");
      if (result) {
        alert("Workshop Added!");
      } else;
    }
  </script>

    <button onclick="showConfirmation()" type="button">Submit</button>
    