<template>
    <div>
        <table class="my-3">
            <tr v-for="(row, rowIndex) of grid" :key="rowIndex-1">
                <td v-for="(ceil, index) of row" :key="index" v-bind:id="index+(rowIndex-1)*row.length" :style="{backgroundColor: ceil.bgColor}" v-bind:class="{'d-none': grid[rowIndex][index].value == -1}">
                    <input type="text" v-if="editMode" v-model="grid[rowIndex][index].value">
                    <span v-if="!editMode">{{ceil.value}}</span>
                </td>
            </tr>
        </table>

        <button class="btn btn-outline-success" @click="gridFilling">Fill the grid</button>
        <button class="btn btn-outline-warning" @click="editGrid">Edit Mode</button>
        <button class="btn btn-outline-primary" @click="solve">Solve fillomino</button>
        <button class="btn btn-outline-danger" @click="removeGrid">Remove this fillomino grid</button>
    </div>
</template>

<script>
    export default {
        name: "fillomino",
        data() {
            return {
                editMode: true,
                itaration: 0,
                bottomDistance: 0,
                topDistance: 0,
                rightDistance: 0,
                leftDistance: 0,
                colors: [
                    'rgba(255,59,0,0.58)',
                    'rgba(255,235,100,0.58)',
                    'rgba(255,144,54,0.58)',
                    'rgba(255,58,58,0.58)',
                    'rgba(79,255,230,0.58)',
                    'rgba(46,41,255,0.58)',
                    'rgba(255,105,252,0.58)',
                    'rgba(100,255,64,0.58)',
                    'rgba(128,0,255,0.58)'
                ]
            }
        },
        props: ['grid', 'width', 'height'],
        methods: {
            gridFilling() {
                let flag = true;
                for (let i = 0; i < this.grid.length; i++) {
                    for (let j = 0; j < this.grid[i].length; j++) {
                        if(i === 0 || i === this.grid.length-1 || j === 0 || j === this.grid[i].length-1) {
                            continue;
                        }
                        if(Number(this.grid[i][j].value) && Number(this.grid[i][j].value) === parseInt(this.grid[i][j].value) && Number(this.grid[i][j].value) > 0 && Number(this.grid[i][j].value) < 10 || this.grid[i][j].value === '') {
                            continue;
                        } else {
                            flag = false;
                        }
                    }
                }
                if (flag) {
                    this.editMode = false;
                } else {
                    alert('You can enter only integer numbers from 1 to 9');
                }
            },
            removeGrid() {
                this.$emit('remove-grid');
            },
            editGrid() {
                this.editMode = true;
            },
            solve() {
                let sum = 0;
                for (let i = 1; i < this.grid.length-1; i++) {
                    for (let j = 1; j < this.grid[i].length-1; j++) {
                        if(Number(this.grid[i][j].value))
                        sum += Number(this.grid[i][j].value);
                    }
                }
                if(sum === (Number(this.width) * Number(this.height))) {
                    for (let i = 1; i < this.grid.length-1; i++) {
                        for (let j = 1; j < this.grid[i].length-1; j++) {
                            for (let k = 1; k < 10; k++) {
                                if(Number(this.grid[i][j].value) === k) {
                                    this.itaration = 0;
                                    this.dfs(i, j, k);
                                    break;
                                }
                            }
                        }
                    }
                    this.editMode = true;  //
                    this.editMode = false; //render
                    this.changeMessage('Fillomino was successfully resolved');
                } else {
                   let conf = confirm('Error! The sum of all entered numbers must correspond to the product of the width and height of the grid. Want to see what happens?');
                   if(conf) {
                       for (let i = 1; i < this.grid.length-1; i++) {
                           for (let j = 1; j < this.grid[i].length-1; j++) {
                               for (let k = 1; k < 10; k++) {
                                   if(Number(this.grid[i][j].value) === k) {
                                       this.itaration = 0;
                                       this.dfs(i, j, k);
                                       break;
                                   }
                               }
                           }
                       }
                       this.editMode = true;  //
                       this.editMode = false; //render
                   }
                }

            },
            dfs(x, y, n) {
                if(Number(this.grid[x][y].value) === n && this.itaration < n  && Number(this.grid[x][y].value) != -1 && this.grid[x][y].visited === false){
                    this.itaration += 1;
                    this.grid[x][y].visited = true;
                    this.grid[x][y].bgColor = this.colors[n-1];
                    this.dfs(x+1, y, n);
                    this.dfs(x-1, y, n);
                    this.dfs(x, y+1, n);
                    this.dfs(x, y-1, n);
                }
                if (this.grid[x][y].value === '' && this.itaration < n) {
                    this.grid[x][y].value = n;
                    this.grid[x][y].visited = true;
                    this.grid[x][y].bgColor = this.colors[n-1];
                    this.itaration += 1;
                    this.dfs(x+1, y, n);
                    this.dfs(x-1, y, n);
                    this.dfs(x, y+1, n);
                    this.dfs(x, y-1, n);

                }
            },
            changeMessage(mes) {
                this.$emit('change-message', mes);
            }
        },
        created() {
            for (let i = 0; i < this.grid.length; i++)
                for (let j = 0; j < this.grid[i].length; j++) {
                    if(i === 0 || i === this.grid.length-1 || j === 0 || j === this.grid[i].length-1) {
                        this.grid[i][j] = {value: -1, visited: true, bgColor: '#fff'};
                    } else
                        this.grid[i][j] = {value: '', visited: false, bgColor: '#fff'};
                }

        }
    }
</script>

<style lang="scss" scoped>
    table {
        margin: 0 auto;
        tr {
            td {
                width: 50px;
                height: 50px;
                border: 1px solid black;
                input {
                    width: 100%;
                    text-align: center;
                }
            }
        }
    }
    .btn-outline-warning {
        &:hover {
            color: white;
        }
    }
    .btn {
        margin-right: 1rem;
    }
</style>
