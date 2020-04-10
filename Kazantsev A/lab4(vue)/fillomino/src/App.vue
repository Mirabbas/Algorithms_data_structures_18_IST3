<template>
  <div id="app">
      <h1>Fillomino</h1>
      <div class="input-group w-26 mx-auto mb-3" v-if="!render">
          <div class="input-group-prepend">
              <span class="input-group-text">Enter width and height</span>
          </div>
          <input type="text" v-model="width" placeholder="width" aria-label="width" class="form-control text-center" >
          <input type="text" v-model="height" placeholder="height" aria-label="height" class="form-control text-center">
      </div>
      <h3 v-bind:class="{green: render, red: !render}">{{ message }}</h3>
      <h3 v-if="render">{{size}}</h3>
      <Fillomino
        v-bind:grid="grid"
        v-if="render"
        :height="height"
        :width="width"
        @change-message="changeMessage"
        @remove-grid="removeGrid"
      />
      <button class="btn btn-outline-success" @click="renderGrid" v-if="!render">Create fillomino</button>
  </div>
</template>

<script>


import Fillomino from "./components/fillomino";
export default {
    name: 'App',
    components: {
        Fillomino
    },
    data() {
        return {
            height: null,
            width: null,
            grid: null,
            render: false,
            message: ''
        }
    },
    methods: {
        renderGrid() {
            if (Number(this.height) && Number(this.width)) {
                this.width = parseInt(this.width);
                this.height = parseInt(this.height);
                this.grid = new Array(this.height+2);
                for (let i = 0; i < this.grid.length; i++) {
                    this.grid[i] = new Array(this.width+2);
                }
                this.render = true;
                this.message = `Fillomino grid has been created`;
                this.size = `Fillomino size: ${this.width}x${this.height}`;

            } else {
                this.message = `Fillomino grid was not created, enter integers`;
            }
        },
        removeGrid() {
            this.width = '';
            this.height = '';
            this.render = false;
            this.message = `Fillomino grid has been removed`;
        },
        changeMessage(mes) {
            this.message = mes;
        }
    }
}
</script>

<style lang="scss">
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
  font-size: 1.5rem;
}
    .green {
        color: #4c800d;
    }
    .red {
        color: #ff2023;
    }
    .w-26 {
        width: 26%;
    }
</style>
